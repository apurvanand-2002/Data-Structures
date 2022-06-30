int x, y;
    if (p != NULL)
    {
        x = height((*(p)).lchild);
        y = height((*(p)).rchild);
        return x - y;
    }
    else
    {
        return 0;
    }