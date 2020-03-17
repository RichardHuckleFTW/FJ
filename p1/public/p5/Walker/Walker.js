class Walker {
  constructor() {
    this.rad = 4;
    this.pos = createVector(windowW / 2, windowH / 2);
    this.vel = p5.Vector.random2D();
  }
  update() {
    constrain(this.pos.x, 0, windowW);
    constrain(this.pos.y, 0, windowH);
    this.pos.add(this.vel);
    this.vel = p5.Vector.random2D();
  }
  render() {
    stroke(255);
    point(this.pos.x, this.pos.y);
  }
}