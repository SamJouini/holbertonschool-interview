#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const characters = JSON.parse(body).characters;

  // Fetch characters one at a time to preserve the order of the list
  const printCharacter = (index) => {
    if (index >= characters.length) {
      return;
    }

    request(characters[index], (err, res, charBody) => {
      if (err) {
        console.error(err);
        return;
      }
      console.log(JSON.parse(charBody).name);
      printCharacter(index + 1);
    });
  };

  printCharacter(0);
});
