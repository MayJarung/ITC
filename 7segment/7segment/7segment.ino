int bitPattern [10] = {B11000000, B11111001, B10100100, B10110000, B10011001, B10010010, B10000010, B11011000, B10000000, B10010000};
const byte numPins = 8;
const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int a = 1;
int b = 0;
int b2 = 0;
int randomNo;

void setup()
{
  for (int i = 0; i < numPins; i++)       // ให้ i เริ่มที่ 0 แล้วรันไปเรื่อยๆ โดยค่าเพิ่มทีละ 1 จนกว่า i จะ < จำนวนพินทั้งหมด กะคือ 8 กะคือรันจนถึง 7
    pinMode(segmentPins[i], OUTPUT);      // ให้ segmentPins[i] เป็น output
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  randomSeed(analogRead(A0));             // ใช้คำสั้งสุ่ม โดยทำการอ่านค่าจาก A0 ซึ่งเป็นค่าที่ error ซึ่งมีเยอะ ทำให้สุ่มไดหลายเลขมากขึ้น
  randomNo = random(1, 10);               // ทำการสุ่มจากเลข 1-9 เอาค่าที่สุ่มได้ไปเก็บไว้ในตัวตัวแปร ramdomNo
}

void loop()
{
  int ck = digitalRead(10);    // อ่านค่าที่พิน 10 มาเก็บไว้ในตัวแปร ck
  boolean isBitSet;

  if (ck == 1 && b == 0)       // ถ้า ck==1 (กดสวิตอยู่) และถ้า b ยังเป็น 0 ให้ b เป็น 1 แล้วเพิ่มค่า a ขึ้นไป 1
  {                            //เอา b มาช่วยให้สวิตไม่กดซ้ำ
    b = 1;
    a++;
  }
  else if (ck == 0) b = 0;     // ถ้า ck==0 (ไม่ได้กดสวิตอยู่)ให้ b กลับมาเป็น 0

  if (a == 10) a = 1;          // ถ้า a รันถึงเลขชุดที่ 10 แล้ว (แสดงถึงเลข 9) ให้ค่า a ให้ค่า a กลับมาเป็น 1 ใหม่

  for (int segment = 0; segment < 8; segment++)   // segment เริ่มต้น = 0 โดยทำงานใน loop ไปเรื่อยๆ โดยเพิ่มค่าทีละ 1 จนกว่าจะน้อยกว่า 8
  {
    isBitSet = bitRead(bitPattern[a], segment);   // ให้ segment (พิน) อ่านค่าใน bitPattern โดยเริ่มจาก a=1 
    digitalWrite(segmentPins[segment], isBitSet); // แสดงค่าจากที่อ่านได้ใน isBitSet ออกมาเป็นตัวเลข บลาๆ 1 2 3
  }
  watt();                        // เรียกใช้ฟังชันก์ watt
}

void watt()                      // ฟังก์ชั่นของสวิตที่ 2 ที่เอาไว้สุ่มค่า
{
  boolean isBit;
  boolean SetisBit;
  int ck2 = digitalRead(11);     // ให้ ck2 อ่านค่าที่พิน 11
  if (ck2 == 1 && b2 == 0)       // ถ้า ck2==1 (กดสวิตอยู่) และถ้า b2 ยังเป็น 0 ให้ b2 เป็น 1
  {
    b2 = 1;
    if (a == randomNo)           // ถ้าค่าเลขที่แสดง(a) = ค่าที่สุ่มได้ จะสั่งให้ a เป็น 0 (แสดงเลข 0) แล้วจะทำการสุ่มเลขใหม่
    {
      a = 0;
      randomNo = random(1, 10);
    }
    else if (a > randomNo)                             // ถ้าค่าเลขที่แสดง(a) > ค่าที่สุ่มได้ โดยเราให้ตัวแปร g = บิตอันนั้นที่แสดงบน 7segment แล้วเป็นตัว G
    {
      int g = B11000010;
      for (int segment = 0; segment < 8; segment++)    // จากนั้นให้ segment เริ่มค่าที่ 0 โดยทำงานใน loop ไปเรื่อยๆ โดยเพิ่มค่าทีละ 1 จนกว่าจะน้อยกว่า 8
      {
        isBit = bitRead(g, segment);                   // ให้ตัวแปร isBit = อ่านค่า g
        digitalWrite(segmentPins[segment], isBit);     // แสดงค่าจากที่อ่านได้ใน isBit ออกมาเป็นตัว G
      }
      delay(1000);
    }
    else if (a < randomNo)                             // ถ้าค่าเลขที่แสดง(a) < ค่าที่สุ่มได้ โดยเราให้ตัวแปร l = บิตอันนั้นที่แสดงบน 7segment แล้วเป็นตัว L
    {
      int l = B11000111;
      for (int segment = 0; segment < 8; segment++)    // จากนั้นให้ segment เริ่มค่าที่ 0 โดยทำงานใน loop ไปเรื่อยๆ โดยเพิ่มค่าทีละ 1 จนกว่าจะน้อยกว่า 8
      {
        SetisBit = bitRead(l, segment);                // ให้ตัวแปร isBit = อ่านค่า g
        digitalWrite(segmentPins[segment], SetisBit);  // แสดงค่าจากที่อ่านได้ใน isBit ออกมาเป็นตัว L
      }
      delay(1000);
    }
  }
  else if (ck2 == 0) b2 = 0;                           // ถ้า ck2==0 (ไม่ได้กดสวิตอยู่) ให้ b2 กลับมาเป็น 0
}
