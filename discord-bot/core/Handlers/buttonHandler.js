const fs = require('fs');
const path = require('path');

module.exports = async (interaction) => {

    const buttonPath =
        path.join(__dirname, '../Buttons');

    const files =
        fs.readdirSync(buttonPath);

    for (const file of files) {

        const button =
            require(path.join(buttonPath, file));

        if (
            button.customId ===
            interaction.customId
        ) {

            return button.execute(
                interaction
            );
        }
    }
};