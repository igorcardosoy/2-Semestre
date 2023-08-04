var number = parseInt(prompt("Digite um numero:"));
var aux = number;
var size = number;

while (aux != 1) {

    aux -= 1;
    number = number * aux;

}

document.write(number);
