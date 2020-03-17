let pg;
let x;
let y;
let sliderCol;
let sliderRow;
let amp = 50;
let totalCirclesCols = 2;
let totalCirclesRows = 1;
let colsSeperation = 80;
let inc = 1;
let smallSize = 5;
let time = 0;
let coorX = [];
let coorY = [];
function setup() {
  createCanvas(windowWidth, windowHeight);
  pg = createGraphics(windowWidth, windowHeight);
  sliderCol = createSlider(1, 19, 10);
  sliderRow = createSlider(1, 9, 5);
  sliderCol.input(function () {
    pg.clear();
  });
  sliderRow.input(function () {
    pg.clear();
  });
}

function draw() {
  image(pg, 0, 0);
  firstX = windowWidth / 50 + colsSeperation;
  firstY = windowHeight / 15;
  background(0, 20);
  noFill();
  for (i = 0, c = 1; i < sliderCol.value(); i++, c += inc) {
    let currentX = cos(c * time) * (amp / 2);
    let currentY = sin(c * time) * (amp / 2);
    stroke(255, 30);
    ellipse(firstX, firstY, amp);
    fill(255);
    coorX.push({ x: firstX + currentX, y: firstY + currentY });
    ellipse(firstX + currentX, firstY + currentY, smallSize);
    noFill();
    firstX += colsSeperation;
  }
  firstX = 1000 / 35;
  firstY = 1000 / 20 + colsSeperation;
  for (i = 0, c = 1; i < sliderRow.value(); i++, c += 1) {
    let currentX = cos(c * time) * (amp / 2);
    let currentY = sin(c * time) * (amp / 2);
    stroke(255, 30);
    ellipse(firstX, firstY, amp);
    fill(255);
    coorY.push({ x: firstX + currentX, y: firstY + currentY });
    ellipse(firstX + currentX, firstY + currentY, smallSize);
    noFill();
    firstY += colsSeperation;
  }
  pg.background(0, 12);
  for (let i = 0; i < coorX.length; i++) {
    for (let j = 0; j < coorY.length; j++) {
      pg.noStroke();
      pg.fill(255, 14, 20);
      pg.ellipse(coorX[i].x, coorY[j].y, smallSize / 2);
    }
  }

  let lastcoorY = coorY[coorY.length - 1];
  let lastcoorX = coorX[coorX.length - 1];
  for (let i = 0; i < coorX.length; i++) {
    stroke(255, 30);
    line(coorX[i].x, coorX[i].y, coorX[i].x, lastcoorY.y);
  }
  for (let i = 0; i < coorY.length; i++) {
    stroke(255, 30);
    line(coorY[i].x, coorY[i].y, lastcoorX.x, coorY[i].y);
  }



  for (let i = 0; i < coorX.length; i++) {
    for (let j = 0; j < coorY.length; j++) {
      let currentX = coorX[i];
      let currentY = coorY[j];
      stroke(255, 14, 20);
      fill(255);
      ellipse(currentX.x, currentY.y, smallSize / 1.5);
    }
  }


  coorX = [];
  coorY = [];
  time += 0.01;

}