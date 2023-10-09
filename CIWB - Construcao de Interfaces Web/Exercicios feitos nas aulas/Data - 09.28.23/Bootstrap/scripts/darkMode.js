const buttonDarkMode = document.querySelector(".darkMode");
const html = document.querySelector("html");
const submiteButton = document.querySelector(".submit");
let darkMode = true;

buttonDarkMode.addEventListener("click", () => {

    if (darkMode == true) {
        html.removeAttribute("data-bs-theme");
        html.setAttribute("data-bs-theme", "light");
        buttonDarkMode.removeAttribute("class");
        buttonDarkMode.setAttribute("class", "btn btn-light");
        
        buttonDarkMode.innerHTML = "Tema escuro";
        darkMode = false;
    } else {
        html.removeAttribute("data-bs-theme");
        html.setAttribute("data-bs-theme", "dark");
        buttonDarkMode.removeAttribute("class");
        buttonDarkMode.setAttribute("class", "btn btn-dark");
        buttonDarkMode.innerHTML = "Tema claro";
        darkMode = true;
    }  
})
