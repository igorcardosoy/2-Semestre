const allButtons = document.getElementsByTagName("button");
const input = document.querySelector("input");

let position = 0;
let number = [];
let op;

for (let index = 0; index < allButtons.length; index++) {
    allButtons[index].addEventListener("click", () => {
        
        let keyPressed = allButtons[index].innerHTML

        if (!isNaN(keyPressed) || keyPressed == ".") {
            input.value += keyPressed;
        }
        else
        {
            switch (keyPressed) {
                case "←":
                    input.value = input.value.slice(0, input.value.length - 1);
                    break;
                case "CE":
                    input.value = null;
                    break;
                case "C":
                    number[0] = null;
                    number[1] = null;
                    position = 0;
                    operator = null;
                    input.value = null;
                    break;
                case "/":
                    number[position] = (input.value);
                    input.value = null;

                    op = "/";

                    if (position == 1) {
                        position = 0;
                        number[0] = parseFloat(number[0]) / parseFloat(number[1]);
                        input.value = number[0];
                    }
                    position++;
                    break;
                case "*":
                    number[position] = (input.value);
                    input.value = null;

                    op = "*";

                    if (position == 1) {
                        position = 0;
                        number[0] = parseFloat(number[0]) * parseFloat(number[1]);
                        input.value = number[0];
                    }
                    position++;
                    break;
                case "+":
                    number[position] = (input.value);
                    input.value = null;

                    op = "+";

                    if (position == 1) {
                        position = 0;
                        number[0] = parseFloat(number[0]) + parseFloat(number[1]);
                        input.value = number[0];
                    }
                    position++;
                    break;
                case "-":
                    number[position] = (input.value);
                    input.value = null;

                    op = "-";

                    if (position == 1) {
                        position = 0;
                        number[0] = parseFloat(number[0]) - parseFloat(number[1]);
                        input.value = number[0];
                    }
                    position++;
                    break;
                case "=":

                    number[position] = parseFloat(input.value);
                    position = 0;

                    switch (op) {
                        case "+":
                            number[0] = parseFloat(number[0]) + parseFloat(number[1]);
                            break;
                        case "-":
                            number[0] = parseFloat(number[0]) - parseFloat(number[1]);
                            break;
                        case "/":
                            number[0] = parseFloat(number[0]) / parseFloat(number[1]);
                            break;
                        case "*":
                            number[0] = parseFloat(number[0]) * parseFloat(number[1]);
                            break;
                        default:
                        break;
                    }

                    position = 0;
                    input.value = number[0];

                    break;
                default:
                    console.log("Não encontrado!");
                    break;
            }
        }

    });
}