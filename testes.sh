#!/bin/bash
ulimit -s unlimited

for tipo_alg in QC QM3 QI1 QI5 QI10 QNR QPE
do
	for tipo_vetor in Ale OrdC OrdD
	do
		for n in {50000..500000..50000}
		do
			$1 $tipo_alg $tipo_vetor $n >> out.txt
		done

		echo "Terminado: $tipo_alg $tipo_vetor"
	done
done

ulimit -s 8192
