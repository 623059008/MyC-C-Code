target : filediff.o diff.o optionsget.o      
       g++ -o target filediff.o diff.o optionsget.o      
filediff.o : filediff.cpp
       g++ -c filediff.cpp
diff.o : diff.cpp
       g++ -c diff.cpp
optionsget.o : optionsget.cpp
       g++ -c optionsget.cpp
clean:
        rm -rf *.o filediff