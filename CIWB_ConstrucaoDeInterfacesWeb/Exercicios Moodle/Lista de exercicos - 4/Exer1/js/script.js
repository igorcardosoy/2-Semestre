const allButtons = document.getElementsByTagName("button");
const input = document.querySelector("input");

let position = 0;
let number = [];
let op;


// Reseta todos os parametros
function resetAll() {
    number[0] = NaN;
    number[1] = NaN;
    position = 0;
    input.value = null;
}


// Funções para fazer as contas.
function division(){
    number[0] = parseFloat(number[0]) / parseFloat(number[1]);
}
function plus(){
    number[0] = parseFloat(number[0]) + parseFloat(number[1]);
}
function minus(){
    number[0] = parseFloat(number[0]) - parseFloat(number[1]);
}
function multiply(){
    number[0] = parseFloat(number[0]) * parseFloat(number[1]);
}

// Decide qual o metodo correto para fazer a operação
function methods(operation) {
    switch (operation) {
        case "/":
            division();
            break;
        case "*":
            multiply();
            break;
        case "-":
            minus();
            break;
        case "+":
            plus();
            break;
        default:
            break;
    }
}

// Faz o calculo com a operação e muda os parametros.
function doCalc(operation) {
    number[position] = (input.value);
    input.value = null;

    op = operation;

    if (position == 1) {
        position = 0;
        methods(operation);
        input.value = number[0];
    }
    position++;
}

for (let index = 0; index < allButtons.length; index++) {
    allButtons[index].addEventListener("click", () => {

        let keyPressed = allButtons[index].innerHTML;

        if (!isNaN(keyPressed) || keyPressed == ".") {
            input.value += keyPressed;
        }
        else {
            switch (keyPressed) {
                case "←":
                    input.value = input.value.slice(0, input.value.length - 1);
                    break;
                case "CE":
                    input.value = null;
                    break;
                case "C":
                    resetAll();
                    break;
                case "/":
                    doCalc("/");
                    break;
                case "*":
                    doCalc("*");
                    break;
                case "+":
                    doCalc("+");
                    break;
                case "-":
                    doCalc("-");
                    break;
                case "=":
                    if (!isNaN(number[0]))
                        number[position] = parseFloat(input.value);
                    if (!isNaN(number[1])) {
                        position = 0;
                        methods(op);
                        input.value = number[0];
                    }
                    break;
                default:
                    console.log("Não encontrado!");
                    break;
            }
        }

    });
}
