/*
 Name:		Primzahlen.ino
 Created:	09.11.2018 20:56:06
 Author:	Johannes
*/

int size = 1;
int* arr = new int[size];

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	Serial.println("Bitte gebe einen gültigen Wertebereich ein.");
}

// the loop function runs over and over again until power down or reset
void loop() {

	if (Serial.available()) {

		int i = Serial.parseInt();
		if (i < 2) {
			Serial.println("Bitte definiere einen gültigen Wertebereich (x >= 2).");
			return;
		}

		findPrimenumbers(i);

		for (int x = 0; x < size; x++) {
			if (arr[x] != NULL) Serial.println(arr[x]);
		}

		Serial.println("Bitte gebe einen gültigen Wertebereich ein, damit die nächste Kalkulation gestartet werden kann.");

	}

}

void findPrimenumbers(int range) {
	for (int x = 2; x <= range; x++) { //0 und 1 sind keine Primzahlen
		boolean isPrime = true;
		for (int y = 1; y <= x; y++) {
			if (x % y == 0 && y != x && y != 1) { //Wenn x geteilt durch y keinen Rest ergibt und y nicht x entspricht und y nicht 1 entspricht, so handelt es sich um keine Primzahl.
				isPrime = false;
				break;
			}
		}
		if (isPrime) addToArray(x);
	}
}

void addToArray(int value) {
	int s = countArray();
	int x = 1;

	int* arr2 = new int[size];

	while (s >= size) { //Arraygröße erhöhen
		delete[] arr2;
		arr2 = new int[s + x];
		x++;
		size++;
	}

	if (s >= size) { //Arrays "austauschen"
		for (int v = 0; v < s; v++) {
			arr2[v] = arr[v];
		}

		arr = arr2;
	}

	arr[s] = value;
}

int countArray() {
	int count = 0;
	for (int x = 0; x < size; x++) {
		if (arr[x] != NULL) count++; //Prüfen, ob die Stelle x im Array besetzt ist.
	}
	return count;
}