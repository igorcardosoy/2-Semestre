let allButtons = document.getElementsByTagName("button");

for (let index = 0; index < allButtons.length; index++) {
    allButtons[index].addEventListener("click", () => {
        console.log(allButtons[index].innerHTML);

        let keyPressed = allButtons[index].innerHTML;

        if (!isNaN(keyPressed)) {
            console.log(parseInt(keyPressed))
        }

    });
}