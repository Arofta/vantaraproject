const buttonHandler =
    require('../Handlers/buttonHandler');

const modalHandler =
    require('../Handlers/modalHandler');

module.exports = {

    name: 'interactionCreate',

    async execute(interaction) {

        if (interaction.isButton()) {
            return buttonHandler(interaction);
        }

        if (interaction.isModalSubmit()) {
            return modalHandler(interaction);
        }
    }
};