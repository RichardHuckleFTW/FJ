class Stream {
  constructor(x) {
    this.x = x;
    this.y = random(-500, -1000);
    this.z = random(0, 20);
    this.length = round(map(this.z, 0, 20, 20, 8));
    this.speed = map(this.z, 0, 20, 1, 15);
    this.letters = new Array(this.length).fill(0);
    this.distant = 50;
    this.iteration = round(random(2, 5));
    this.pos = round(random(0, this.length));
  }

  update() {
    this.y += this.speed;
    let pos = round(random(0, this.length));
    this.letters[pos] = String.fromCharCode(0x30A0 + round(random(0, 96)));
  }

  draw() {
    textSize(letterSize);
    fill(255);
    text(this.letters[this.letters.length - 1], this.x, this.y + letterSize * (this.letters.length - 1));
    fill(28, 150, 35);
    for (let i = 0; i < this.letters.length - 1; i++)
      text(this.letters[i], this.x, this.y + letterSize * i);
  }
}