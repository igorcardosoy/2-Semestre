const form = document.querySelector('#form');

form.onsubmit = (e) => {
  e.preventDefault();
  const formData = new FormData(form);
  
    console.log(formData.get('name'));

  localStorage.setItem('name', formData.get('name'));

  window.location.href = 'pagina2.html'
}