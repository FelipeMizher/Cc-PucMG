import 'package:sqflite/sqflite.dart';
import 'package:path/path.dart';

class DatabaseHelper {
  static final DatabaseHelper instance = DatabaseHelper._init();
  static Database? _database;

  DatabaseHelper._init();

  Future<Database> get database async {
    if (_database != null) return _database!;
    _database = await _initDB('eloescolar_local.db');
    return _database!;
  }

  Future<Database> _initDB(String filePath) async {
    final dbPath = await getDatabasesPath();
    final path = join(dbPath, filePath);

    return await openDatabase(
      path,
      version: 2, // ==== VERSÃO INCREMENTADA PARA FORÇAR O UPGRADE ====
      onCreate: _createDB,
      onUpgrade: _upgradeDB, // ==== FUNÇÃO DE ATUALIZAÇÃO ====
    );
  }

  Future _createDB(Database db, int version) async {
    await db.execute('''
      CREATE TABLE favoritos (
        id TEXT PRIMARY KEY,
        titulo TEXT NOT NULL,
        categoria TEXT NOT NULL,
        fotoUrl TEXT,
        descricao TEXT,
        latitude REAL,
        longitude REAL
      )
    ''');
  }

  // Se o usuário já tinha o app instalado, adiciona as colunas novas sem apagar os dados dele
  Future _upgradeDB(Database db, int oldVersion, int newVersion) async {
    if (oldVersion < 2) {
      try { await db.execute('ALTER TABLE favoritos ADD COLUMN descricao TEXT'); } catch (_) {}
      try { await db.execute('ALTER TABLE favoritos ADD COLUMN latitude REAL'); } catch (_) {}
      try { await db.execute('ALTER TABLE favoritos ADD COLUMN longitude REAL'); } catch (_) {}
    }
  }

  Future<int> adicionarFavorito(Map<String, dynamic> material, String id) async {
    final db = await instance.database;

    List<dynamic> fotos = material['fotos'] ?? [];
    String? primeiraFoto = fotos.isNotEmpty ? fotos[0].toString() : null;

    final row = {
      'id': id,
      'titulo': material['titulo'] ?? 'Sem título',
      'categoria': material['categoria'] ?? 'Outros',
      'fotoUrl': primeiraFoto,
      'descricao': material['descricao'] ?? '', // Salva a descrição corretamente
      'latitude': material['latitude'],
      'longitude': material['longitude'],
    };

    return await db.insert(
      'favoritos',
      row,
      conflictAlgorithm: ConflictAlgorithm.replace,
    );
  }

  Future<List<Map<String, dynamic>>> buscarTodosFavoritos() async {
    final db = await instance.database;
    return await db.query('favoritos');
  }

  Future<int> removerFavorito(String id) async {
    final db = await instance.database;
    return await db.delete(
      'favoritos',
      where: 'id = ?',
      whereArgs: [id],
    );
  }

  Future<bool> isFavoritado(String id) async {
    final db = await instance.database;
    final maps = await db.query(
      'favoritos',
      where: 'id = ?',
      whereArgs: [id],
    );
    return maps.isNotEmpty;
  }

  Future close() async {
    final db = await instance.database;
    db.close();
  }
}