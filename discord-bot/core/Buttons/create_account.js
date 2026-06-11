const {
    ModalBuilder,
    TextInputBuilder,
    TextInputStyle,
    ActionRowBuilder
} = require('discord.js');

const db =
    require('../database');

const PraInvalid =
    require('../Components/create_account/pra-invalid');

const Invalid3 =
    require('../Components/create_account/invalid3');

module.exports = {

    customId: 'create_account',

    async execute(interaction) {

        try {

            const [rows] = await db.query(
                `SELECT account_name
                 FROM player_accounts
                 WHERE account_discord_id = ?
                 LIMIT 1`,
                [interaction.user.id]
            );

            if (rows.length) {
                
                const accountName =
                    rows[0].account_name;

                return interaction.reply({
                    embeds: [PraInvalid(accountName)],
                    ephemeral: true
                });
            }

            const modal = new ModalBuilder()
                .setCustomId('create_account')
                .setTitle('Create Account');

            const accountName =
                new TextInputBuilder()
                    .setCustomId('account_name')
                    .setLabel('Account Name')
                    .setStyle(TextInputStyle.Short)
                    .setMinLength(4)
                    .setMaxLength(24)
                    .setRequired(true);

            modal.addComponents(
                new ActionRowBuilder()
                    .addComponents(accountName)
            );

            await interaction.showModal(modal);

        } catch (err) {

            console.error(
                '[CREATE ACCOUNT BUTTON ERROR]',
                err
            );

            return interaction.reply({
                embeds: [Invalid3()],
                ephemeral: true
            });
        }
    }
};