const $startGameButton = document.querySelector(".start-quiz")
const $nextQuestionButton = document.querySelector(".next-question")
const $questionsContainer = document.querySelector(".questions-container")
const $questionText = document.querySelector(".question")
const $answersContainer = document.querySelector(".answers-container")
const $answers = document.querySelectorAll(".answer")

let currentQuestionIndex = 0
let totalCorrect = 0

$startGameButton.addEventListener("click", startGame)
$nextQuestionButton.addEventListener("click", displayNextQuestion)

function startGame() {
  $startGameButton.classList.add("hide")
  $questionsContainer.classList.remove("hide")
  displayNextQuestion()
}

function displayNextQuestion() {
  resetState()

  if (questions.length === currentQuestionIndex) {
    return finishGame()
  }

  $questionText.textContent = questions[currentQuestionIndex].question
  questions[currentQuestionIndex].answers.forEach(answer => {
    const newAsnwer = document.createElement("button")
    newAsnwer.classList.add("button", "answer")
    newAsnwer.textContent = answer.text
    if (answer.correct) {
      newAsnwer.dataset.correct = answer.correct
    }
    $answersContainer.appendChild(newAsnwer)

    newAsnwer.addEventListener("click", selectAnswer)
  })
}

function resetState() {
  while($answersContainer.firstChild) {
    $answersContainer.removeChild($answersContainer.firstChild)
  }

  document.body.removeAttribute("class")
  $nextQuestionButton.classList.add("hide")
}

function selectAnswer(event) {
  const answerClicked = event.target

  if (answerClicked.dataset.correct) {
    document.body.classList.add("correct")
    totalCorrect++
  } else {
    document.body.classList.add("incorrect") 
  }

  document.querySelectorAll(".answer").forEach(button => {
    button.disabled = true

    if (button.dataset.correct) {
      button.classList.add("correct")
    } else {
      button.classList.add("incorrect")
    }
  })

  $nextQuestionButton.classList.remove("hide")
  currentQuestionIndex++
}

function finishGame() {
  const totalQuestions = questions.length
  const performance = Math.floor(totalCorrect * 100 / totalQuestions)

  let message = ""

  switch (true) {
    case (performance >= 90):
      message = "Você entende bem o idioma :)"
      break
    case (performance >= 70):
      message = "Tá entendendo Leagal :)"
      break
    case (performance >= 50):
      message = "Estude para melhorar ainda mais "
      break
    default:
      message = "Você precisa estudar mais sobre o idioma :("
  }

  $questionsContainer.innerHTML = 
  `
    <p class="final-message">
      Você acertou ${totalCorrect} de ${totalQuestions} questões!
      <span>Resultado: ${message}</span>
    </p>
    <button 
      onclick=window.location.reload() 
      class="button"
    >
      Refazer teste
    </button>
  `
}


const questions = [
  {
    question: 'Qual das frases abaixo está escrita corretamente em inglês?',
    answers: [
      { text: "I has a cat", correct: false },
      { text: "You is my best friend", correct: false },
      { text: "She have two dogs", correct: true },
      { text: "They are at the park", correct: false }
    ]
  },
  {
    question: 'Qual a tradução da palavra "OLA" do Português para o Inglês?',
    answers: [
      { text: "Hello", correct: true },
      { text: "How", correct: false },
      { text: "Must", correct: false },
      { text: "Green", correct: false }
    ]
  },
  {
    question: 'Qual o verbo que preenche corretamente a lacuna na seguinte frase: "I ____ to school every day."',
    answers: [
      { text: 'Goes', correct: false },
      { text: 'Going', correct: true },
      { text: 'Go', correct: false },
      { text: "Went", correct: false }
    ]
  },
  {
    question: 'Qual das frases abaixo está escrita corretamente em inglês?',
    answers: [
      { text: "She does't like coffee", correct: false },
      { text: "He have a lot of books", correct: false },
      { text: "They were happy to see us", correct: false },
      { text: "You goes to the gym every day", correct: true }
    ]
  },
  {
    question: 'ual o verbo que preenche corretamente a lacuna na seguinte frase: "My brother ____ to the store yesterday."',
    answers: [
      { text: 'Go', correct: true },
      { text: 'Goes', correct: false },
      { text: 'Going', correct: false },
      { text: 'Went', correct: false }
    ]
  },
  {
    question: 'Qual a tradução da palavra "cachorro" para o inglês?',
    answers: [
      { text: 'Cat', correct: false },
      { text: 'Dog', correct: true },
      { text: 'Bird', correct: false },
      { text: 'Fish', correct: false }
    ]
  },
  {
    question: 'Qual a forma correta de escrever "obrigado" em inglês?',
    answers: [
      { text: 'Hello', correct: false },
      { text: 'Goodbye', correct: false },
      { text: 'Welcome', correct: false },
      { text: 'Thanks', correct: true },
    ]
  },
]