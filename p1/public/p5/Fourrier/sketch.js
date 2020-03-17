let windowW = 1000;
let windowH = 600;
let time = 0;
let bigX = 300.33333333333334;
let bigY = 250;
let ys = [];
let prevx = bigX;
let prevy = bigY;
let lastX;
let lastY;
let sign;
let c;
let n = 500;
let size = 180;
let drawingPointX = bigX + 400;
function setup() {
  createCanvas(windowW, windowH);
}

function draw() {
  background(100);
  prevx = bigX;
  prevy = bigY;
  for (c = 1; c < n; c += 2) {
    let amp = 4 / (c * PI) * size;
    let x = cos(c * time) * (amp / 2);
    let y = sin(c * time) * (amp / 2);
    noFill();
    ellipse(prevx, prevy, amp);
    fill(0);
    line(prevx, prevy, prevx + x, prevy + y);
    prevx += x;
    prevy += y;
    ellipse(prevx, prevy, 5);
  }
  lastX = prevx;
  lastY = prevy;
  stroke(0);
  line(lastX, lastY, drawingPointX, lastY);
  push()
  fill(0);
  triangle(drawingPointX - 5, lastY + 5, drawingPointX - 5, lastY - 5, drawingPointX, lastY);
  pop()
  ys.push({ x: drawingPointX, y: lastY });

  for (let i = 0; i < ys.length - 1; i++) {
    let currentCoor = ys[i];
    let nextCoor = ys[i + 1];
    if (currentCoor.x >= windowW) ys.splice(i--, 1);
    else {
      line(currentCoor.x, currentCoor.y, nextCoor.x, nextCoor.y);
      ys[i].x++;
    }
  }
  time -= 0.02;
}