const Invalid1 =
    require('../Components/reffund_role/invalid1');

const Invalid2 =
    require('../Components/reffund_role/invalid2');

const Invalid3 =
    require('../Components/reffund_role/invalid3');

const Success =
    require('../Components/reffund_role/success');

const db =
    require('../database');

module.exports = {

    customId: 'reffund_role',

    async execute(interaction) {

        if (interaction.member.roles.cache.has(process.env.ROLE_WARGA)) {
            
            return interaction.reply({
                embeds: [Invalid1()],
                ephemeral: true
            });
        }

        try {

            const [rows] = await db.query(
                `SELECT account_name FROM 
                 player_accounts WHERE 
                 account_discord_id = ?`,
                 [interaction.user.id]
            );

            if (rows.length) {
                
                await interaction.member.roles.add(process.env.ROLE_WARGA);

                return interaction.reply({
                    embeds: [Success()],
                    ephemeral: true
                });
            } else {

                return interaction.reply({
                    embeds: [Invalid2()],
                    ephemeral: true
                });
            }
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