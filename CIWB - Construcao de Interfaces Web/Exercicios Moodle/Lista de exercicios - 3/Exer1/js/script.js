const input = document.querySelector(".input");

function onClick() {

    const inputValue = input.value;
    const li = document.querySelector(".lista").children;

    if (inputValue[0] != undefined) {
        console.log("Entrada valida!");

        for (let i = 0; i < li.length; i++) {

            if (hasString(li[i], inputValue)) {
                li[i] = li[i].style.cssText =
                    "font-weight: bold;" +
                    "color: rgb(236, 189, 255);";
            } else {
                li[i] = li[i].style.cssText =
                    "font-weight: none;" +
                    "color: aliceblue;";
            }
            
        }

    } else {
        console.log("Entrada invalida!");
    }

    if (inputValue[0] == undefined) {
        for (let i = 0; i < li.length; i++) {
                li[i] = li[i].style.cssText =
                    "font-weight: none;" +
                    "color: aliceblue;";
        }
    }

}

function hasString(li, inputValue) {
    let findsCount = 0;


    for (let index = 0; index < inputValue.length; index++) {
        if (li.textContent[index] === inputValue[index]) {
            findsCount++;
        }
    }

    if (findsCount === inputValue.length) {
        return true;
    } else {
        return false;
    }
}

input.addEventListener("keyup", onClick);

let button = document.querySelector(".button");

input.addEventListener("keypress", function (e) {
    if (e.key === 'Enter') {
        onClick();
    }
}); 