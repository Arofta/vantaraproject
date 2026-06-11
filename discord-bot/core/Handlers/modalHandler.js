const fs = require('fs');
const path = require('path');

module.exports = async (interaction) => {

    const modalPath =
        path.join(__dirname, '../Modals');

    const files =
        fs.readdirSync(modalPath);

    for (const file of files) {

        const modal =
            require(path.join(modalPath, file));

        if (
            modal.customId ===
            interaction.customId
        ) {

            return modal.execute(
                interaction
            );
        }
    }
};