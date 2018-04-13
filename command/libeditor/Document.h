#pragma once
#include "IDocument.h"
#include "IDocumentItem.h"
#include "IFileResource.h"
#include "History.h"
#include "DocumentResourcePath.h"

class CDocument : public IDocument
{
	typedef std::list<IDocumentItem::Ptr> DocumentItemsList;

public:
	CDocument();

	std::shared_ptr<IParagraph> InsertParagraph(std::string const & text, boost::optional<size_t> position = boost::none) override;
	std::shared_ptr<IImage> InsertImage(boost::filesystem::path const & path, unsigned width, unsigned height, boost::optional<size_t> position = boost::none) override;

	/**/ size_t GetItemsCount() const override;

	IDocumentItem::Ptr GetItem(size_t index) const override;
	IDocumentItem::ConstPtr GetItem(size_t index) override;

	void DeleteItem(size_t index) override;
	
	void SetTitle(std::string const & title) override;
	std::string GetTitle() const override;

	bool CanUndo() const override;
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

	void Save(boost::filesystem::path const & path) const override;

private:
	IFileResource::Ptr GetCopiedImageResource(boost::filesystem::path source);
	void ValidateInsertPosition(boost::optional<size_t> position) const;
	void ValidateItemPosition(boost::optional<size_t> position) const;

	std::string m_title;
	DocumentItemsList m_items;
	CHistory m_history;
	CDocumentResourcePath m_resourcePath;
};