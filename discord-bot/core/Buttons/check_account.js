const Success1 =
    require('../Components/check_account/success1');

const Success2 =
    require('../Components/check_account/success2');

const Invalid1 = 
    require('../Components/check_account/invalid1');
    
const Invalid2 = 
    require('../Components/check_account/invalid2');

const db =
    require('../database');

module.exports = {

    customId: 'check_account',

    async execute(interaction) {

        try {

            const [rows] = await db.query(
                `SELECT account_name, 
                 account_verify, 
                 account_recovery 
                 FROM player_accounts 
                 WHERE account_discord_id = ? LIMIT 1`, 
                 [interaction.user.id]
            );

            if (rows.length) {

                const accountName = 
                    rows[0].account_name;

                const verifyCode =
                    rows[0].account_verify;

                const recoveryCode =
                    rows[0].account_recovery;

                if (verifyCode !== -1) {
                    
                    const accountStatus = 
                        'Unverified';

                    const codeStatus = 
                        'Verification'

                    return interaction.reply({
                        embeds: [Success1(accountName, accountStatus, codeStatus, verifyCode)],
                        ephemeral: true
                    });
                } else if (recoveryCode !== -1) {
                    
                    const accountStatus = 
                        'Recovery';

                    return interaction.reply({
                        embeds: [Success1(accountName, accountStatus, accountStatus, recoveryCode)],
                        ephemeral: true
                    });
                } else {

                    const accountStatus = 
                        'Verified';

                    return interaction.reply({
                        embeds: [Success2(accountName, accountStatus)],
                        ephemeral: true
                    });
                }
            }

            return interaction.reply({
                embeds: [Invalid1()],
                ephemeral: true
            });
        } catch (err) {

            console.error(
                '[CHECK ACCOUNT BUTTON ERROR]',
                err
            );

            return interaction.reply({
                embeds: [Invalid2()],
                ephemeral: true
            });
        }
    }
};