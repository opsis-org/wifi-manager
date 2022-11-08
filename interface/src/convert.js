const fs = require('fs');

// Create output files
createTxtFile();
createHexFile();

// Clean intermediate files
fs.unlinkSync('./dist/index.html.gz');
fs.unlinkSync('./dist/index.html');

// Creates a 96 character wide file containing minimized html that
// can be served to requests not accepting gzipped responses
function createTxtFile() {
    // The minimized file took us from 7.5kb to 4.4kb
    const input = fs.readFileSync('./dist/index.html', 'utf8');
    const escaped = input.replaceAll('"','\\"');

    let column = 0;
    let output = '';

    // This is a bit funky but we need to ensure that
    // we dont insert a new line at a \" because that
    // would would break the syntax for the output.
    for (let i = 0; i < escaped.length; i++) {
        const character = escaped.substring(i, i+1);

        output += character;
        column++;

        if (column > 96 && character !== '\\') {
            output += '"\n"';
            column = 0;
        }
    }

    // Writing output file escaping the whole columned string
    fs.writeFileSync('./dist/index.txt', `"${output}"`);
}

// Creates a 16 hex column file containing gzipped html that
// can be served to requests accepting gzipped responses
function createHexFile() {
    // The gzipped file took us from 4.4kb to 1.8kb
    const input = fs.readFileSync('./dist/index.html.gz', 'hex');

    let output = '';
    let column = 0;

    // Generates a hex string with max 16 hex values in one column
    // before it breaks to next line. This can be pasted into
    // Data.cpp to be served as the gzipped index file.
    for (let i = 0; i < input.length; i += 2) {
        const value = `${input[i]}${input[i+1]}`

        output += `0x${value.toUpperCase()}`;

        if (column++ === 15) {
            output += ',\n'
            column = 0;
        } else if (i + 2 < input.length) {
            output += ', '
        }
    }

    // Writing output file
    fs.writeFileSync('./dist/index.hex', output);
}
