const inputEmail = document.querySelector("#userEmail")
const inputPassword = document.querySelector("#userPassword")
const registerButton = document.querySelector("#registerButton")

function cleanInput(){
    inputEmail.value = ""
    inputPassword.value = ""
}

registerButton.addEventListener("click", cleanInput)

