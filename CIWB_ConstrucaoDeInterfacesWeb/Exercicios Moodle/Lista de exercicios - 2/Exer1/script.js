const botao = document.querySelector("#botao");
const input = document.querySelector("#num");
const tabuada = document.querySelector("#tabuada");
const TABUADA_SIZE = 10;

function criarTabuada() {
    let num = input.value;

    console.log(num);

    for (let index = 1; index <= TABUADA_SIZE; index++) {

        let text = document.createTextNode(index + "x" + num + " = " + num * index);

        let tag_p = document.createElement("p");
        tag_p.appendChild(text);

        console.log(tag_p);

        tabuada.appendChild(tag_p);
        tabuada.style.display = "flex";
    }

    let tag_hr = document.createElement("hr");

    tabuada.appendChild(tag_hr);

}

input.addEventListener("keypress", function (e) {
    if (e.key === 'Enter') {
        criarTabuada();
    }
});

botao.addEventListener("click", criarTabuada);

