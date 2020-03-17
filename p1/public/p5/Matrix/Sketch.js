var windowH = 500;
var windowW = 800;
var totalStreams = 20;
var streamArray = [];
var letterSize = 20;
var gravity = 10;

function setup() {
  createCanvas(windowW, windowH);
  for (let i = 0; i < windowW; i += letterSize)
    streamArray.push(new Stream(i));
  console.log(streamArray);
}

function draw() {
  background(0);
  streamArray.forEach(stream => {
    stream.update();
    stream.draw();
  });
  for (let i = 0; i < streamArray.length; i++) {
    if (streamArray[i].y > windowH) {
      streamArray[i] = new Stream(i * letterSize);
      console.log(streamArray.length);
    }
  }
}
