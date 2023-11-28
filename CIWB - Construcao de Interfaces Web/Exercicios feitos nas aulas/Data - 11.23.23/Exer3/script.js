class GreaterThan50 extends Error {
    constructor(message) {
        super(message);
        this.name = "GreaterThan50";
    }
} // OBRIGADO MEU AMOR EU TE AMO INFINTO, AGRADEÇO POR DEIXAR ABERTO E EU PODER COPIAR. Hoje a noote te pago (.) (.) . s2 <3

const form = document.querySelector('#form')

form.onsubmit = (e) => {
    e.preventDefault();
    const formData = new FormData(form)
    let num = formData.get('num')

    try {
        if (isNaN(num)) {
            throw new Error('O valor informado não é um número')
        } else if (num > 50) {
            throw new GreaterThan50('O valor informado é maior que 50')
        }
        alert(`O número é menor que 50! (${num})`)
    } catch (error) {
        alert(error)
    }
}