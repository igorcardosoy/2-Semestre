const form = document.querySelector('#form')

form.onsubmit = (e) => {
    e.preventDefault();
    const formData = new FormData(form)
    let num = formData.get('num')

    try {
        num = parseInt(num)
        if (isNaN(num)) {
            throw new Error('O valor informado não é um número')
        }
        alert(`O número convertido foi ${num}`)
    } catch (error) {
        alert(error.message)
    }

    num = parseInt(num);
}