#ifndef SERVERDNATTRSUPDATER_H
#define SERVERDNATTRSUPDATER_H

#include <QString>

class AdInterface;
class QByteArray;

class ServerDnAttrsUpdater {
public:
    ServerDnAttrsUpdater(const QString &server_dn);

    void update_for_delete(AdInterface &ad);
    void update_for_move(AdInterface &ad, const QString &new_server_dn);

private:
    void update_replica_locations(AdInterface &ad, const QString &new_server_dn);
    void update_fsmo_role_owner(AdInterface &ad, const QString &new_server_dn);
    void update_inter_site_topology_generator(AdInterface &ad, const QString &new_server_dn);

    void cleanup_missing_site_dn_values(QList<QByteArray> &server_setts_dn_list, const QStringList &actual_site_list);

    QString dn;
};

#endif // SERVERDNATTRSUPDATER_H
