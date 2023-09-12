const inputMin = document.querySelector("#inputMin");
const inputMax = document.querySelector("#inputMax");
const button = document.querySelector("#buttonCount");
const divNumbers = document.querySelector("#number");


function createElementP(number) {


    const tagP = document.createElement("p");
    const text = document.createTextNode(number);

    tagP.appendChild(text);
    divNumbers.appendChild(tagP);

}

function onClick() {

    let inputMaxValue = parseInt(inputMax.value);
    let inputMinValue = parseInt(inputMin.value);

    inputMax.value = null;
    inputMin.value = null;

    if (inputMaxValue > inputMinValue && inputMaxValue != undefined && inputMinValue != undefined) {
        console.log("Valores validos!");

        divNumbers.style.display = "flex";

        for (let index = inputMinValue ; index <= inputMaxValue; index++) {

            if (index % 2 === 0 && index % 3 === 0) {
                createElementP(index);
            }
        }
    } else {
        console.log("Valores invalidos!");
        alert("Valores invalidos!");
    }
}

inputMin.addEventListener("keypress", function (e) {
    if (e.key === 'Enter') {
        onClick();
    }
});

inputMax.addEventListener("keypress", function (e) {
    if (e.key === 'Enter') {
        onClick();
    }
});

button.addEventListener("click", onClick);  