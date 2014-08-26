#!/usr/bin/env bash

COMP="c++"
ARGSBASE=""

INFILE="loop.cpp"
OUTFILE="loop"

echo "Running with no optimization..."
ARGS="${ARGSBASE} -O0"
eval "${COMP} ${ARGS} ${INFILE} -o ${OUTFILE}"
./${OUTFILE}
echo ""

echo "Running with optimization 1..."
ARGS="${ARGSBASE} -O1"
eval "${COMP} ${ARGS} ${INFILE} -o ${OUTFILE}"
./${OUTFILE}
echo ""

echo "Running with optimization 2..."
ARGS="${ARGSBASE} -O2"
eval "${COMP} ${ARGS} ${INFILE} -o ${OUTFILE}"
./${OUTFILE}
echo ""

echo "Running with optimization s..."
ARGS="${ARGSBASE} -Os"
eval "${COMP} ${ARGS} ${INFILE} -o ${OUTFILE}"
./${OUTFILE}
echo ""

echo "Running with optimization g..."
ARGS="${ARGSBASE} -Og"
eval "${COMP} ${ARGS} ${INFILE} -o ${OUTFILE}"
./${OUTFILE}
echo ""

echo "Running with optimization 3..."
ARGS="${ARGSBASE} -O3"
eval "${COMP} ${ARGS} ${INFILE} -o ${OUTFILE}"
./${OUTFILE}
echo ""

echo "Running with optimization fast..."
ARGS="${ARGSBASE} -Ofast"
eval "${COMP} ${ARGS} ${INFILE} -o ${OUTFILE}"
./${OUTFILE}
echo ""

echo "Running with optimization 4..."
ARGS="${ARGSBASE} -O4"
eval "${COMP} ${ARGS} ${INFILE} -o ${OUTFILE}"
./${OUTFILE}
echo ""

