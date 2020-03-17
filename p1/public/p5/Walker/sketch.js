let windowW = 400;
let windowH = 400;
let w;
function setup() {
  createCanvas(windowW, windowH);
  background(0);
  w = new Walker();
}

function draw() {
  for (let i = 0; i < 100; i++) {
    w.update();
    w.render();
  }
}