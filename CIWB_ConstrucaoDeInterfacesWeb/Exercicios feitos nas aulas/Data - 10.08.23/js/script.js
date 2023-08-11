document.getElementsByTagName("h1")[0].textContent = "AAAAAAAAA";

document.getElementById("link").href = "https://www.google.com/";

var class_dm = document.getElementsByClassName("dm"); // Variaveis se transformam nessa função. No caso de um id não é vetor, mas classe sim.


class_dm[0].style.color = "red"; //Suporta cores RGB também
class_dm[1].style.color = "green";

var link_a = document.querySelector("a#link"); // Da mesma forma que o CSS. Os seletores CSS.

link_a.style.color = "red";
link_a.remove(); // Excluir o elemento

var tag_body = document.querySelector("body");
var tag_p = document.createElement("p");
var text_p = document.createTextNode("Meu texto que veio do JS");

// Forma 1
// var attr_p = document.createAttribute("class");
// attr_p.value = "dm";
// tag_p.setAttributeNode(attr_p);

// Forma 2
tag_p.setAttribute("class", "dm");

tag_p.appendChild(text_p); //Tag p recebe como filho o texto
tag_body.appendChild(tag_p); // Tag body recebe tag p como filho (body > p > text_p)

tag_p.style.color = "green";

//Botao

function click_botao()
{
    alert("Clicou");
}

var botao = document.querySelector("#botao");
botao.addEventListener("click", click_botao);