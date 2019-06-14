#!/bin/bash
ulimit -s unlimited

function anakin {
	pkill -P $$
	ulimit -s 8192
}

trap anakin EXIT

rm out.txt testes-sh-log.txt

for tipo_alg in QC QM3 QI1 QI5 QI10 QNR QPE
do
	for tipo_vetor in Ale OrdC OrdD
	do
		for n in {50000..500000..50000}
		do
			bin/main $tipo_alg $tipo_vetor $n >> out.txt
		done
		echo "`date +\[%H:%M:%S\]` terminado: $tipo_alg $tipo_vetor" >> testes-sh-log.txt
	done
done
