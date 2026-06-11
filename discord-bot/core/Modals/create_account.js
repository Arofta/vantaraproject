const db =
    require('../database');

const Invalid1 =
    require('../Components/create_account/invalid1');

const Invalid2 =
    require('../Components/create_account/invalid2');

const Invalid3 =
    require('../Components/create_account/invalid3');

const Success =
    require('../Components/create_account/success');

module.exports = {

    customId: 'create_account',

    async execute(interaction) {

        const accountName = 
            interaction.fields.getTextInputValue('account_name');

        const validNameRegex =
            /^[A-Za-z0-9]+$/;

        if (!validNameRegex.test(accountName)) {

            return interaction.reply({
                embeds: [Invalid1()],
                ephemeral: true
            });
        }

        try {

            const [rows] = await db.query(
                `SELECT account_name
                 FROM player_accounts
                 WHERE account_name = ?
                 LIMIT 1`,
                [accountName]
            );

            if (rows.length) {

                return interaction.reply({
                    embeds: [Invalid2(accountName)],
                    ephemeral: true
                });
            }

            const verifyCode =
                Math.floor(Math.random() * 888889) + 111111;

            await db.query(
                `INSERT INTO player_accounts
                (
                    account_name,
                    account_discord_id,
                    account_verify,
                    account_recovery,
                    account_register_date
                )
                VALUES (?, ?, ?, -1, CURRENT_TIMESTAMP)`,
                [
                    accountName,
                    interaction.user.id,
                    verifyCode
                ]
            );

            return interaction.reply({
                embeds: [Success(accountName, verifyCode)],
                ephemeral: true
            });

        } catch (err) {

            console.error(
                '[CREATE ACCOUNT ERROR]',
                err
            );

            return interaction.reply({
                embeds: [Invalid3()],
                ephemeral: true
            });
        }
    }
};