#include "AVL.h"

int AVL::height(Nodes* node)
{
    int h = 0;
    // helps break recursion cycle
    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);

        int maxH = (leftH, rightH);
        h = maxH + 1;

    }
    return h;
}

int AVL::difference(Nodes* node)
{
    // if tree is empty its balanced
    if (node == NULL)
        return 0;

    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balnceFactor = leftH - rightH;

    return balnceFactor;
}

Nodes* AVL::RRrotation(Nodes* parent)
{
    Nodes* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;
    if (displayRotaton) 
        cout << " RR roation on " << parent->levelnumber << endl;
    
    return temp;
}

Nodes* AVL::LLrotation(Nodes* parent)
{
    Nodes* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    if (displayRotatons)
        cout << " RR roation on " << parent->levelnumber << endl;

    return temp;
}

Nodes* AVL::RLrotation(Nodes* parent)
{
    Nodes* temp = parent->rightChild;
    parent->rightChild = RRrotation(temp);
    temp->leftChild = parent;
    if (displayRotatons)
        cout << " RL roation on " << parent->levelnumber << endl;
    // swaps left and rights
    return RRrotation(parent);
}

Nodes* AVL::LRrotation(Nodes* parent)
{
    Nodes* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    if (displayRotatons)
        cout << " LR roation on " << parent->levelnumber<< endl;
    return LLrotation(parent);
}

Nodes* AVL::balance(Nodes* parent)
{
    // get balance factor
    int balanceFactor = difference(parent);
    // left tree - right tree height
    // if balanceFactor not within -1,0,1 work out what rotations to do
    if (balanceFactor > 1)
    {
        // left branch is heavy now work out is left or right child heavy
        if (difference(parent->leftChild) > 0)
        {
            // gotta work out the child to see which way to rotate
            // * left child unbalanced *
            parent = LLrotation(parent);
        }
        else
        {// right child unbalanced
            parent = LRrotation(parent);

        }
    }
    else if (balanceFactor < -1)
    {
        // right branch is heavy
        if (difference(parent->rightChild) > 0)
        {
            parent = RLrotation(parent);

        }
        else
        {
            // right child heavy
            parent = RRrotation(parent);

        }
    } // if balance factor is within the range the if structured can be skipped

    return parent;
}

Nodes* AVL::insertAVL(Nodes* parent, Nodes*newLevel )
{
    // this function will keep calling parent, (recursive)
    // if sub tree empty, this becomes the parent
    if (parent == NULL)
    {
        parent = newLevel;
        return parent;
    }

    // parent not null, so we haven't found an empty space to stick new students yet
    // so we need to go down either right(values towards 12) or left ( values towards 7)

    // AVL can balance its self up after each insert of another parent
    if (newLevel->levelnumber < parent->levelnumber)
    {
        parent->leftChild = insertAVL(parent->leftChild, newLevel);
        parent = balance(parent);
    }
    // assume id >= parent id
    else
    {

        parent->rightChild = insertAVL(parent->rightChild, newLevel);
        parent = balance(parent);
    }


}

void AVL::insert(Nodes* newLevel)
{
    cout << "inserting " << newLevel->levelname << " " << newLevel->levelnumber<< endl;
    root = insertAVL(root, newLevel);
    cout << endl;

}
