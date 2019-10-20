Socio *makenodeSocio()
{
    Socio *nv;
    nv = (Socio *)malloc(sizeof(Socio));
    nv->nseg = NULL;
    return (nv);
}
Socio *insertlastSocio(Socio *M, Socio *nv)
{

    Socio *aux = M;
    if (M == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return M;
}
Participacao *makenodeParticipacao()
{
    Participacao *nv;
    nv = (Participacao *)malloc(sizeof(Participacao));
    nv->nseg = NULL;
    return (nv);
}
Participacao *insertlastParticipacao(Participacao *M, Participacao *nv)
{

    Participacao *aux = M;
    if (M == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return M;
}
Evento *makenodeEvento()
{
    Evento *nv;
    nv = (Evento *)malloc(sizeof(Evento));
    nv->nseg = NULL;
    return (nv);
}
Evento *insertlastEvento(Evento *M, Evento *nv)
{

    Evento *aux = M;
    if (M == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return M;
}