bin/testTableEntry: testTableEntry.cpp TableEntry.h
		mkdir -p bin
		g++ -o bin/testTableEntry testTableEntry.cpp

clean:
	rm -rf *.o *.gch																	
bin/testHashTable: HashTable.h Dict.h TableEntry.h testHashTable.cpp 
		mkdir -p bin						
		g++ -o bin/testHashTable testHashTable.cpp HashTable.h

clean:
	rm -rf *.o *.gch
~                            
