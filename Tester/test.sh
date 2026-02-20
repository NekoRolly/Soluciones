for ((i = 1; i <= 100; ++i)); do
	echo "Running test" $i
	./generator > "input.txt"
	./my_solution < "input.txt" > "my_output.txt"
    # ./verificador < "my_output.txt" > "veredicto"
	./good_solution < "input.txt" > "good_output.txt"
	diff -w "my_output.txt" "good_output.txt" || break
done