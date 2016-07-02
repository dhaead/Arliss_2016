void stest(){
  if (myFile) {
    Serial.print("Writing to navsdtest.txt...");
    myFile.println("testing 1, 2, 1.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("navsdtest.txt");
  if (myFile) {
    Serial.println("navsdtest.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening navsdtest.txt");
  }
}



