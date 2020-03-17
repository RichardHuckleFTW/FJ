const testDir = __dirname + '/public/test.html';
const express = require('express');
const app = express();
app.use(express.static(__dirname + '/public'));
app.get('/', (req, res) => {
  let dir = __dirname + "/public/main.html";
  res.sendFile(dir);
});
app.use(express.static(__dirname + '/public/p5'));
app.get('/Fourrier', (req, res) => {
  let dir = __dirname + "/public/p5/index.html";
  res.sendFile(dir);
});
app.get('/Matrix', (req, res) => {
  let dir = __dirname + "/public/p5/Matrix/index.html";
  res.sendFile(dir);
});

app.get('/Lissajous', (req, res) => {
  let dir = __dirname + "/public/p5/Lissajous/index.html";
  res.sendFile(dir);
});

app.get('/Walker', (req, res) => {
  let dir = __dirname + "/public/p5/Walker/index.html";
  res.sendFile(dir);
});
app.listen(3000, () => console.log("Listening To Port 3000"));