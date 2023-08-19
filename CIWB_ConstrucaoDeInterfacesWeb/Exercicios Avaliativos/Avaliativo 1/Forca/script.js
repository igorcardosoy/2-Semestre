// Lista de palavras
const words = [
    "banana",
    "maçã",
    "pera",
    "uva",
    "laranja",
    "abacate",
    "melancia",
    "mamão",
    "goiaba",
    "manga",
    "morango",
    "kiwi",
    "abacaxi",
    "caqui",
    "cereja",
    "damasco",
    "figo",
    "groselha",
    "jabuticaba",
    "lichia",
    "nêspera",
    "pêssego",
    "tamarindo",
    "tomate",
    "abelha",
    "abobrinha",
    "abdômen",
    "abraço",
    "acidente",
    "acampamento",
    "açúcar",
    "acuidade",
    "açougueiro",
    "adubo",
    "adolescência",
    "adulto",
    "afeto",
    "agitação",
    "águia",
    "agulha",
    "água",
    "ágil",
    "ala",
    "alface",
    "alaúde",
    "alegria",
    "alerta",
    "alfabeto",
    "aldeia",
    "alienígena",
    "alergia",
    "alarde",
    "alicerce",
    "almanaque",
    "almofada",
    "alopécia",
    "alpinista",
    "alto-falante",
    "alvoroço",
    "amado",
    "amarelo",
    "amêndoa",
    "ameríndio",
    "amor",
    "âncora",
    "anêmona",
    "anestesia",
    "aneurisma",
    "ânimo",
    "ano",
    "antídoto",
    "antena",
    "antibiótico",
    "antipatia",
    "apêndice",
    "apetite",
    "aranha",
    "árvore",
    "arara",
    "azul",
    "beija-flor",
    "bicicleta",
    "cachorro",
    "carro",
    "casa",
    "céu",
    "criança",
    "chuva",
    "cidade",
    "computador",
    "comida",
    "coração",
    "cor",
    "criança",
    "dança",
    "dia",
    "dinheiro",
    "desenho",
    "doença",
    "escola",
    "esporte",
    "estrela",
    "família",
    "festa",
    "flor",
    "fogo",
    "floresta",
    "fruta",
    "gato",
    "amigo",
    "história",
    "hora",
    "hotel",
    "jardim",
    "jogo",
    "livro",
    "lua",
    "mar",
    "mãe",
    "matemática",
    "médico",
    "música",
    "natureza",
    "noite",
    "número",
    "oceano",
    "olho",
    "pai",
    "papel",
    "parque",
    "pessoa",
    "planeta",
    "poema",
    "porta",
    "praia",
    "professor",
    "quarto",
    "rio",
    "roupa",
    "escola",
    "sapato",
    "sol",
    "sopa",
    "televisão",
    "telefone",
    "tempo",
    "terra",
    "teatro",
    "tempo",
    "tília",
    "toalha",
    "árvore",
    "trânsito",
    "trem",
    "viagem",
    "água",
    "verde",
    "vinho",
    "vida",
    "voz",
    "vinho",
    "viagem",
    "água"
  ];

// A palavra sera sorteada
var palavra = words[Math.floor(Math.random() * words.length)];
console.log(palavra);

// E o espaço onde os underline serão substituidos pelas letras. Tem o [] para ser um vetor.
var mensagem = [];

// Define a quantidade de vidas
var vida = 6;

// Contador de imagens, serve para mudar as imagens da forca.
var img = 0;

// Flag para saber se ganhou ou não
var ganhou = 0;

// Coloca os underline no vetor mensagem
for (let i = 0; i < palavra.length; i++) {
    // O push coloca im valor no vetor
    mensagem.push(" _ ");
}

// Coloca os underlines no HTML. O join serve para não ter virgulas no texto, mas sim espaços.
document.querySelector("#letras").textContent = mensagem.join(' ');

// Botão de enviar a letra
var botao = document.querySelector("#botao");

// Evento para quando clicar no botao a função rodar.
botao.addEventListener("click", () => {

    // Uma flag, serve para saber se uma letra ja foi usada.
    let repetida = false;

    // A letra a ser digitada
    var letra = "";

    // Pega o valor do input.
    letra = document.querySelector("#campo").value;

    // Deixa as letras minusculas, para não ter erro de letra maiuscula e minuscula
    letra = letra.toLowerCase();

    // Contador
    let i = 0;

    // Define se vai perder vida ou não, uma flag.
    let achou = false; 

    // Verifica se a pessoa digitou algo valido
    if (letra[0] == undefined) {
        repetida = true;
    }

    // Vai definir a variavel usadas para "um atalho" para o <p> no HTML, de letras digitadas
    var usadas = document.querySelector("#letras_utilizadas");
    for (let index = 1; index < palavra.length; index++) {
        // Se a letra digitada for igual a um caracter que ja esta registrado no HTML.
        if (letra[0] == usadas.textContent.charAt(index).toLowerCase() ) {
            // Joga um alerta de letra repitida e define a flag repitida como true.
            alert("Letra Repetida!");
            repetida = true;
        }
    }

    // Se a letra não for repetida:
    if (!repetida) {
        // Enquanto i for menor que o tamanho da palavra. 
        while (i < palavra.length) {

            // Se a primeira letra digitada pelo usuario for igual a alguma da palavra:
            if (letra[0] == palavra[i]) {
                // Troca 1 caracter da posição i pela letra da posição i.
                mensagem.splice(i, 1, palavra[i]);

                // Atualiza o texto da palavra
                document.querySelector("#letras").textContent = mensagem.join(' ');

                // Define a flag achou como true, para saber que uma letra foi digitada corretamente
                achou = true;

                ganhou += 1;
            }

            i++;
        }

        // Se não achou a letra digitada:
        if (!achou) {

            // Perde uma vida
            vida--;

            // Atualiza o contador de imagens
            img++;

            // Atualiza a imagem, de acordo com o num do contador
            document.querySelector("#enforcado").setAttribute("src", "images/nivel" + img + ".png")

        }

        // Se a vida for menor ou igual a 0:
        if (vida <= 0) {

            // Coloca um texto na tag <p> com o id #morte 
            document.querySelector("#morte").textContent = "Você Morreu!";

            // Coloca um atributo de estilo, display none, para o botao sumir a visao do usuario.
            document.querySelector("#botao").setAttribute("style", "display: none");

            // Cria um "atalho" para a tag <p> com id #reviver
            reviver = document.querySelector("#reviver");

            // Coloca o texto na tag com id #reviver
            document.querySelector("#reviver").textContent = "Reviver";

            // Adiciona um envento de click, que quando clicar executa a função discreta
            reviver.addEventListener("click", () => {

                // Redefine a vida, a tag de letras usadas, o contador de imagens, redefine para a imagem inicial.
                vida = 6;
                usadas.textContent = "";
                img = 0;
                document.querySelector("#enforcado").setAttribute("src", "images/nivel" + img + ".png")

                // Muda o atributo display, para block, assim o botão volta a aparecer para o usuario
                document.querySelector("#botao").setAttribute("style", "display: block");

                // Retira o texto das tag de #morte e #reviver. 
                document.querySelector("#morte").textContent = "";
                document.querySelector("#reviver").textContent = "";

                palavra = words[Math.floor(Math.random() * words.length)];
                console.log(palavra);

                // Zera o array das underlines
                mensagem = [];

                // Coloca novamente as underlines
                for (let i = 0; i < palavra.length; i++) {
                    mensagem.push(" _ ");
                }
                document.querySelector("#letras").textContent = mensagem.join(' ');
            })

        }

        // Confere se ganhou cehgou ao tamanho da palavra
        if (ganhou >= palavra.length) {
            // Coloca um atributo de estilo, display none, para o botao sumir a visao do usuario.
            document.querySelector("#botao").setAttribute("style", "display: none");

            document.querySelector("#campo").setAttribute("style", "display: none");

            document.querySelector("#letras_utilizadas").setAttribute("style", "display: none");

            document.querySelector("#vitoria").setAttribute("style", "display: block");
            document.querySelector("#vitoria").textContent = "Você ganhou, parabéns!";

            // Cria um "atalho" para a tag <p> com id #reviver
            reviver = document.querySelector("#reviver");

            // Coloca o texto na tag com id #reviver
            document.querySelector("#reviver").textContent = "Jogar novamente";

            // Adiciona um envento de click, que quando clicar executa a função discreta
            reviver.addEventListener("click", () => {

                // Redefine a vida, a tag de letras usadas, o contador de imagens, redefine para a imagem inicial.
                vida = 6;
                usadas.textContent = "";
                img = 0;
                document.querySelector("#enforcado").setAttribute("src", "images/nivel" + img + ".png")

                // Muda o atributo display, para block, assim o botão volta a aparecer para o usuario
                document.querySelector("#botao").setAttribute("style", "display: block");

                document.querySelector("#campo").setAttribute("style", "display: block");

                document.querySelector("#letras_utilizadas").setAttribute("style", "display: block");

                document.querySelector("#vitoria").setAttribute("style", "display: none");

                // Retira o texto das tag de #morte e #reviver. 
                document.querySelector("#morte").textContent = "";
                document.querySelector("#reviver").textContent = "";

                palavra = words[Math.floor(Math.random() * words.length)];
                console.log(palavra);

                // Zera o array das underlines
                mensagem = [];

                // Coloca novamente as underlines
                for (let i = 0; i < palavra.length; i++) {
                    mensagem.push(" _ ");
                }
                document.querySelector("#letras").textContent = mensagem.join(' ');
            })
        }

        // Coloca as letras ja utilizadas na tag <p>, em letras maiusculas.
        document.querySelector("#letras_utilizadas").textContent += " " + letra[0].toUpperCase();
        document.querySelector("#campo").value = "";
        
    }

});