const input = document.querySelector("input");
const button = document.querySelector("button");
const box = document.querySelector("#box")
let AgePhrase = "";


function AgeName(){

    let tagP = document.createElement("p");

    fetch("https://api.agify.io/?name=" + input.value)
    .then(function (respostaJson)
    {
        return respostaJson.json();
    })

    .then(
        function(RespostaDados){

            if (RespostaDados["age"] == null) {
                AgePhrase = ("Entrada invalida!!");
                tagP.textContent = AgePhrase;
                box.appendChild(tagP);
            } else {
                AgePhrase = ("O nome "+ '"'+RespostaDados["name"]+ '"'+" tem a idade igual a " + RespostaDados["age"]);
                tagP.textContent = AgePhrase;
                box.appendChild(tagP);
            }

            
            
        }
    )

    input.value = null;
}

button.addEventListener("click", AgeName);

input.addEventListener("keypress", function (e) {
    if (e.key === 'Enter') {
        AgeName();
    }
}); 