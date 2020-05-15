// Program		: matrix.c
// Author		: Rey Rizki
// Description	: Matrix ADT body implementation file
// Date			: Friday, 17 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "matrix.h"

Matrix createMatrix()
{
    Matrix matrix;
    matrix.topLeft = NULL;
    return matrix;
}

Node *createNode()
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = CreatePoint(0, 0);
    
    REP(i, 0, 4)
        node->direction[i] = NULL;

    return node;
}

bool isMatrixEmpty(Matrix matrix)
{
    return matrix.topLeft == NULL;
}

void insertLeftColumn(Matrix *matrix)
{
    address topNode = NULL, trans = matrix->topLeft, node;

    if (isMatrixEmpty(*matrix))
        matrix->topLeft = createNode();
    else
    {
        while (trans != NULL)
        {
            node = createNode();

            if (node != NULL)
            {
                node->direction[right] = trans;
                trans->direction[left] = node;

                node->direction[up] = topNode;
                if (topNode != NULL)
                    topNode->direction[down] = node;

                topNode = node;
                trans = trans->direction[down];
            }
            else
                printf("Overflow");
        }

        matrix->topLeft = matrix->topLeft->direction[left];
    }
}

void insertRightColumn(Matrix *matrix)
{
    address topNode = NULL, trans, node;

    // printf("Yeehaw\n");
    if (isMatrixEmpty(*matrix))
        insertLeftColumn(matrix);
    else
    {
        trans = topRightAddress(*matrix);
        while (trans != NULL)
        {
            node = createNode();

            if (node != NULL)
            {
                node->direction[left] = trans;
                trans->direction[right] = node;

                node->direction[up] = topNode;
                if (topNode != NULL)
                    topNode->direction[down] = node;

                topNode = node;
                trans = trans->direction[down];
            }
            else
                printf("Overflow");
        }
    }
}

void insertTopRow(Matrix *matrix)
{
    address prevNode = NULL, trans = matrix->topLeft, node;

    if (isMatrixEmpty(*matrix))
        matrix->topLeft = createNode();
    else
    {
        while (trans != NULL)
        {
            node = createNode();

            if (node != NULL)
            {
                node->direction[down] = trans;
                trans->direction[up] = node;

                node->direction[left] = prevNode;
                if (prevNode != NULL)
                    prevNode->direction[right] = node;

                prevNode = node;
                trans = trans->direction[right];
            }
            else
                printf("Overflow");
        }

        matrix->topLeft = matrix->topLeft->direction[up];
    }
}

void insertBottomRow(Matrix *matrix)
{
    address prevNode = NULL, trans, node;

    if (isMatrixEmpty(*matrix))
        matrix->topLeft = createNode();
    else
    {
        trans = bottomLeftAddress(*matrix);
        while (trans != NULL)
        {
            node = createNode();

            if (node != NULL)
            {
                node->direction[up] = trans;
                trans->direction[down] = node;

                node->direction[left] = prevNode;
                if (prevNode != NULL)
                    prevNode->direction[right] = node;

                prevNode = node;
                trans = trans->direction[right];
            }
            else
                printf("Overflow");
        }
    }
}

u int columnCount(Matrix matrix)
{
    address trans = matrix.topLeft;
    u int count = 0;

    while (trans != NULL)
    {
        count++;
        trans = trans->direction[right];
    }

    return count;
}

u int rowCount(Matrix matrix)
{
    address trans = matrix.topLeft;
    u int count = 0;

    while (trans != NULL)
    {
        count++;
        trans = trans->direction[down];
    }

    return count;
}

address topRightAddress(Matrix matrix)
{
    address trans = matrix.topLeft;

    while (trans->direction[right] != NULL)
        trans = trans->direction[right];

    return trans;
}

address bottomLeftAddress(Matrix matrix)
{
    address trans = matrix.topLeft;
    
    while (trans->direction[down] != NULL)
        trans = trans->direction[down];
    
    return trans;
}

address addressAt(Matrix matrix, u int row, u int column)
{
    address trans = matrix.topLeft;
    u int countC = 0, countR = 0;

    if ((column > columnCount(matrix)) or (row > rowCount(matrix)))
        return NULL;

    while (countC < column)
    {
        trans = trans->direction[right];
        countC++;
    }

    while (countR < row)
    {
        trans = trans->direction[down];
        countR++;
    }

    return trans;
}

POINT dataAt(Matrix matrix, u int row, u int column)
{
    return (addressAt(matrix, row, column) == NULL) ? CreatePoint(0, 0) : (addressAt(matrix, row, column))->data;
}

void assignNode(Matrix *matrix, u int row, u int column, dataType data)
{
    address target = addressAt(*matrix, row, column);

    if (target != NULL)
        target->data = data;
}

void printMatrix(Matrix matrix)
{
    address rowTrans = matrix.topLeft, columnTrans;

    while (rowTrans != NULL)
    {
        columnTrans = rowTrans;
        while (columnTrans != NULL)
        {
            PrintPoint(columnTrans->data);
            printf((columnTrans->direction[right] == NULL) ? "\n" : " ");

            columnTrans = columnTrans->direction[right];
        }

        rowTrans = rowTrans->direction[down];
    }
}