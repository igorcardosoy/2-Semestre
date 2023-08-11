var body = document.querySelector("body");
var botao = document.querySelector("#interruptor");
var lampada = document.querySelector("img");

function click_botao() {
    if (lampada.hasAttribute("apagada")) {

        lampada.setAttribute("src", "images/ybxlO.jpg");
        lampada.setAttribute("alt", "Lampada acesa");

        lampada.removeAttribute("apagada");
    }
    else {
        lampada.setAttribute("src", "images/b983w.jpg");
        lampada.setAttribute("alt", "Lampada apagada");
        lampada.setAttribute("apagada", "");
    }
}

function explode(){
    lampada.setAttribute("src", "images/quebrada.jpg");
    lampada.setAttribute("alt", "Lampada quebrada");
    body.style.backgroundColor = "red";
}

lampada.addEventListener("click", explode);
botao.addEventListener("click", click_botao);