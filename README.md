# ECE1895-Hello-World

ECE 1895 Junior Design Fundamentals, Assignment 13 (Introduction to Git and GitHub).
Team repository for Chuxuan Zhou (maintainer), Tengyue and Xiaodong.

The code is Chuxuan's Assignment 9 "Hello World" for a standalone ATmega328P
(16 MHz crystal, programmed as an Arduino Uno through a USBtinyISP).

| Sketch | Behavior |
| --- | --- |
| `OneLightBlink/OneLightBlink.ino` | While the button is held, one LED blinks (0.5 s on, 0.5 s off) |
| `ThreeLightBlink/ThreeLightBlink.ino` | While the button is held, three LEDs light in turn; after release the current cycle finishes, then all LEDs stay off |

## Team edits

Everyone edits `ThreeLightBlink/ThreeLightBlink.ino` on their own branch and opens a
pull request into `main`. Nobody commits to `main` directly. Each person adds one
comment line with their name in their own spot, so the three pull requests don't conflict.

| Member | Branch | New comment line goes directly above |
| --- | --- | --- |
| Chuxuan | `ChuxuanZ-edit` | `void allOff() {` |
| Tengyue | `Tengyue` + last-name initial + `-edit` | `void setup() {` |
| Xiaodong | `Xiaodong` + last-name initial + `-edit` | `void loop() {` |

1. Create your branch (first name + last-name initial + `-edit`).
2. Add your comment line and commit it to your branch.
3. Open a pull request into `main`.
4. The maintainer reviews and merges all three pull requests.
5. Clone the repository and check that all three comments are there:

   ```
   git clone https://github.com/CHZ166/ECE1895-Hello-World.git
   ```
