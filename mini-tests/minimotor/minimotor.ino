const int motor1 =  8;
const int motor2 =  9;

void setup() {
  // put your setup code here, to run once:
  pinMode( motor1 , OUTPUT);
  pinMode( motor2 , OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite( motor1 , HIGH);
  digitalWrite( motor2 , LOW);
  delay(5000);
//  digitalWrite( motor1 , LOW);
//  digitalWrite( motor2 , HIGH);
//  delay(5000);
}
