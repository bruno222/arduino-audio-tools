
#include "AudioTools.h"

void print(const char *title, Vector<int> &vector) {
  Serial.println(title);
  for (int j = 0; j < vector.size(); j++) {
    Serial.print(vector[j]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println();
}

void testPushBack() {
  Vector<int> vector;
  for (int j = 0; j < 10; j++) {
    vector.push_back(j);
  }
  print("testPushBack", vector);
  for (int j = 0; j < 10; j++) {
    assert(vector[j] == j);
  }
}

void testPushFront() {
  Vector<int> vector;
  for (int j = 0; j < 10; j++) {
    vector.push_front(j);
  }
  print("testPushFront", vector);

  for (int j = 0; j < 10; j++) {
    assert(vector[9 - j] == j);
  }
}

void testPopFront() {
  Vector<int> vector;
  for (int j = 0; j < 10; j++) {
    vector.push_back(j);
  }
  vector.pop_front();
  print("testPopFront", vector);

  assert(vector.size() == 9);
  for (int j = 0; j < 9; j++) {
    assert(vector[j] == j + 1);
  }
}

void testPopBack() {
  Vector<int> vector;
  for (int j = 0; j < 10; j++) {
    vector.push_back(j);
  }
  vector.pop_back();
  print("testPopBack", vector);

  assert(vector.size() == 9);
  for (int j = 0; j < 9; j++) {
    assert(vector[j] == j);
  }
}

void testErase() {
  Vector<int> vector;
  for (int j = 0; j < 10; j++) {
    vector.push_back(j);
  }
  vector.erase(0);
  print("testErase", vector);

  assert(vector.size() == 9);
  for (int j = 0; j < 9; j++) {
    assert(vector[j] == j + 1);
  }
}

void testCopy() {
  Vector<int> vector;
  for (int j = 0; j < 10; j++) {
    vector.push_back(j);
  }
  print("testCopy", vector);
  Vector<int> v1{vector};
  assert(v1.size()==10);

  Vector<int> v2 = vector;
  assert(v2.size()==10);

  vector.erase(0);
  assert(v1.size()==10);
  assert(v2.size()==10);

  testArg(v1);
}

void testArg(Vector<int> arg){
  print("testArg", arg);
  assert(arg.size()==10);
}


void setup() {
  Serial.begin(115200);
  testPushBack();
  testPushFront();
  testPopFront();
  testPopBack();
  testErase();
  testCopy();
  Serial.print("All tests passed");
}

void loop() {}