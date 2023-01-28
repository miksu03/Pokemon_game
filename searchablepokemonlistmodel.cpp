#include "searchablepokemonlistmodel.h"

SearchablePokemonListModel::SearchablePokemonListModel()
{
    setSourceModel(&m_sourceModel);
}

QString SearchablePokemonListModel::searchString() const
{
    return m_searchString;
}

void SearchablePokemonListModel::setSearchString(QString newString)
{
    if (newString != m_searchString)
    {
        m_searchString = newString;
        emit searchStringChanged();
        invalidateRowsFilter();
    }
}

bool SearchablePokemonListModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    Q_UNUSED(source_parent)
    if (sourceModel() &&
        !m_searchString.isEmpty())
    {
        const QModelIndex sourceIndex = sourceModel()->index(source_row, 0);
        const QString pokemonName = sourceModel()->data(sourceIndex, static_cast<int>(PokemonListModel::Role::Name)).toString();
        return pokemonName.contains(m_searchString, Qt::CaseInsensitive);
    }
    return true;
}
