const Invalid1 =
    require('../Components/account_recovery/invalid1');

const Invalid2 =
    require('../Components/account_recovery/invalid2');

const Invalid3 =
    require('../Components/account_recovery/invalid3');

const Invalid4 =
    require('../Components/account_recovery/invalid4');

const Success =
    require('../Components/account_recovery/success');

const db =
    require('../database');

module.exports = {

    customId: 'account_recovery',

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

                    return interaction.reply({
                        embeds: [Invalid1(accountName, accountStatus, verifyCode)],
                        ephemeral: true
                    });
                } else if (recoveryCode !== -1) {
                    
                    const accountStatus = 
                        'Recovery';

                    return interaction.reply({
                        embeds: [Invalid2(accountName, accountStatus, recoveryCode)],
                        ephemeral: true
                    });
                } else {

                    const rCode =
                        Math.floor(Math.random() * 888889) + 111111;

                    await db.query(
                        `UPDATE player_accounts SET
                         account_recovery = ? WHERE 
                         account_discord_id = ?`,
                         [rCode, interaction.user.id]
                    );
                    
                    const accountStatus = 
                        'Recovery';

                    return interaction.reply({
                        embeds: [Success(accountName, accountStatus, rCode)],
                        ephemeral: true
                    });
                }
            }

            return interaction.reply({
                embeds: [Invalid3()],
                ephemeral: true
            });
        } catch (err) {

            console.error(
                '[CHECK ACCOUNT BUTTON ERROR]',
                err
            );

            return interaction.reply({
                embeds: [Invalid4()],
                ephemeral: true
            });
        }
    }
};
/*
discord-bot/
│
├── core/
│   ├── Buttons/
│   │   ├── account_recovery.js
│   │   ├── create_account.js
│   │   ├── check_account.js
│   │   └── reffund_role.js
│   │   
│   ├── Components/
│   │   ├── accountButton.js
│   │   └── accountPanel.js
│   │
│   ├── Events/
│   │   ├── interactionCreate.js
│   │   └── messageCreate.js
│   │
│   ├── Handlers/
│   │   ├── buttonHandler.js
│   │   └── eventHandler.js
│   │
│   ├── database.js
│   └── index.js
│
├── node_modules/
├── .env
├── package-lock.json
└── package.json
*/
