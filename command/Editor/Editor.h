#pragma once
#include "../libeditor/IDocument.h"

class CEditor
{
public:
	CEditor(IDocument& document, std::istream& in, std::ostream& out);

	void HandleCommand();
	void PrintHelp();
	void PrintCarriage();
	void PrintDocument();

private:
	void InsertParagraph(std::istream& args);
	void InsertImage(std::istream& args);
	void SetTitle(std::istream& args);
	void ReplaceText(std::istream& args);
	void ResizeImage(std::istream& args);
	void DeleteItem(std::istream& args);
	void Undo(std::istream& args);
	void Redo(std::istream& args);
	void Save(std::istream& args);
	std::string ReadLineFromRemainingInput(std::istream& in);
	boost::optional<size_t> ReadPositionFromInput(std::istream& in);

	void ClearConsole();

	typedef std::map<std::string, std::function<void(std::istream& args)>> ActionMap;

	const ActionMap m_actionMap;
	IDocument& m_document;
	std::istream& m_in;
	std::ostream& m_out;
};