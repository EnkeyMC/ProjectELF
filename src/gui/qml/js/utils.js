.pragma library

// Workaround function for mnemonic strings
// Taken from this SO answer: https://stackoverflow.com/questions/54736428/how-to-style-menubaritem-with-mnemonics-strings-in-qml
function formatMnemonicString(txt)
{
    var index = txt.indexOf("&");
    if(index >= 0)
        txt = txt.replace(txt.substr(index, 2), ("<u>" + txt.substr(index + 1, 1) +"</u>"));
    return txt;
}
