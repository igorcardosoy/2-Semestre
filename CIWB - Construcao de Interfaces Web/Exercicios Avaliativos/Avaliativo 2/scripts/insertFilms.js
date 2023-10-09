let template = document.getElementById('molde').innerHTML;
let url_pop = 'https://api.themoviedb.org/3/movie/popular';

// function request() {
//     var resultado;
//     const options = {
//         method: 'GET',
//         headers: {
//           accept: 'application/json',
//           Authorization: 'Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiI2NTNlMmNkMzhmMGZhODA1NDEzNTI2NGE4NmYzOWU2MyIsInN1YiI6IjY1MWYzYzIwYzUwYWQyMDE0ZGQwYTUwMSIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.V5Bxzb7yxVG_K_B_RPKpJKwzLrFGySn7siL1waEUidU'
//         }
//       };
      
//       fetch('https://api.themoviedb.org/3/movie/popular?language=pt-BR&page=1', options)
//         .then(response => response.json())
//         .then(response => resultado = response.results)
//         .catch(err => console.error(err));

//     return resultado;
// }
  

async function request() {
    const options = {
        method: 'GET',
        headers: {
          accept: 'application/json',
          Authorization: 'Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiI2NTNlMmNkMzhmMGZhODA1NDEzNTI2NGE4NmYzOWU2MyIsInN1YiI6IjY1MWYzYzIwYzUwYWQyMDE0ZGQwYTUwMSIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.V5Bxzb7yxVG_K_B_RPKpJKwzLrFGySn7siL1waEUidU'
        }
      };
      
      const data = await fetch('https://api.themoviedb.org/3/movie/popular?language=pt-BR&page=1', options)
      const result = await data.json();
      const resultFinal = await result.results;
    
      resultFinal.forEach(element => {
        document.querySelector('#main').innerHTML += template;
        // template.querySelector('.card-text').textContent += element.title;
      });
}

request()